use rand::Rng;
use rand::seq::SliceRandom;
use std::fs::File;
use std::io::Read;
use std::io::Result;
use std::io::Write;
use std::path::Path;

fn energy(time: f32) -> f32 {
    1f32
}

struct Seed {
    energy: f32,
}

struct Tree {
    id: u32,
    sum_energy: f32,
    location: Location,
}

impl Tree {
    fn new(seed: &Seed, location: &Location) -> Tree {
        static mut SUM_ID: u32 = 0u32;
        let mut tree = Tree {
            id: 0,
            sum_energy: seed.energy,
            location: location.clone(),
        };
        unsafe {
            SUM_ID += 1;
            tree.id = SUM_ID;
        };
        tree
    }

    fn update(&mut self, e: f32) {
        self.sum_energy += e;
    }

    fn info(&self) {
        println!("Tree {0} {1}", self.id, self.sum_energy);
    }

    fn get_chill(&mut self) -> Option<Seed> {
        if self.sum_energy > 100f32 {
            let tmp = self.sum_energy - 100f32;
            self.sum_energy = 100f32;
            Some(Seed { energy: tmp })
        } else {
            None
        }
    }
}

#[derive(Clone, Copy)]
struct Location {
    x: usize,
    y: usize,
}

#[derive(Clone, Copy)]
enum LandTile {
    None,
    Tree,
}

struct Land {
    size_x: usize,
    size_y: usize,
    land: Vec<LandTile>,
}

impl Land {
    fn new(size_x: usize, size_y: usize) -> Land {
        let mut land = Land {
            size_x,
            size_y,
            land: Vec::new(),
        };
        land.land.resize(size_x * size_y, LandTile::None);
        land
    }

    fn get_random_location(&self) -> Location {
        let mut rng = rand::rng();
        Location {
            x: rng.random_range(0..self.size_x),
            y: rng.random_range(0..self.size_y),
        }
    }

    fn set_location(&mut self, location: &Location, land_tile: LandTile) {
        let tmp = location.y * self.size_x + location.x;
        self.land[tmp] = land_tile;
    }

    fn get_location(&self, location: &Location) -> LandTile {
        self.land[location.y * self.size_x + location.x]
    }

    fn save(&self, file_path: &Path) -> Result<()> {
        let mut file = File::create(file_path)?;
        let bytes = self.size_x.to_le_bytes();
        file.write_all(&bytes)?;
        let bytes = self.size_y.to_le_bytes();
        file.write_all(&bytes)?;
        let count = self.size_y * self.size_x;
        let mut bytes: Vec<u8> = vec![0u8; count];
        for (index, item) in self.land.iter().enumerate() {
            bytes[index] = match item {
                LandTile::None => 0u8,
                LandTile::Tree => 1u8,
            };
        }
        file.write_all(&bytes)?;
        Ok(())
    }

    fn load(file_path: &Path) -> Result<Land> {
        let mut file = File::open(file_path)?;
        let mut bytes = [0u8; 8];
        file.read_exact(&mut bytes)?;
        let size_x = usize::from_le_bytes(bytes);
        file.read_exact(&mut bytes)?;
        let size_y = usize::from_le_bytes(bytes);
        let count = size_y * size_x;
        let mut bytes: Vec<u8> = vec![0u8; count];
        file.read_exact(&mut bytes)?;
        let mut land = Land::new(size_x, size_y);
        for (index, item) in bytes.iter().enumerate() {
            land.land[index] = match item {
                0u8 => LandTile::None,
                _ => LandTile::Tree,
            }
        }
        Ok(land)
    }
}

fn main() {
    let mut time = 0f32;
    let land_path = Path::new("data/land.bin");
    let mut land = match Land::load(land_path) {
        Ok(land) => land,
        Err(_) => Land::new(1024usize, 1024usize),
    };

    let location = land.get_random_location();
    let mut trees = vec![Tree::new(&Seed { energy: 1f32 }, &location)];
    land.set_location(&location, LandTile::Tree);

    let mut rng = rand::rng();
    let mut chill_trees: Vec<Seed> = Vec::new();

    loop {
        time += 1f32;
        let e = energy(time);
        trees.shuffle(&mut rng);
        for tree in &mut trees {
            tree.update(e);
            if let Some(chill) = tree.get_chill() {
                chill_trees.push(chill);
            }
        }
        let mut need_save = false;
        for chill in &chill_trees {
            let location = land.get_random_location();
            if let LandTile::None = land.get_location(&location) {
                need_save = true;
                trees.push(Tree::new(chill, &location));
            }
        }
        if need_save {
            land.save(land_path).expect("Error save map");
        }
        println!("Sum {}", trees.len());
    }
}
