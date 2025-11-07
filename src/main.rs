struct Time {
    pub time: f32,
}

impl Time {
    pub fn update(&mut self, delta: f32) {
        self.time += delta;
    }
}

fn main() {
    println!("Hello, world!");

    let mut time = Time { time: 0f32 };
    let mut count = 0u32;
    loop {
        time.update(0.1);
        count += 1;

        println!("Sum time {}", time.time);
        if count >= 100 {
            break;
        }
    }
}
