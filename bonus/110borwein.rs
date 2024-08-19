use std::io::{self, Write};

const INTERVAL_END: f64 = 5000.0;
const NUM_SUBINTERVALS: f64 = 10000.0;

fn print_error() {
    println!("Invalid argument -h for help");
}

fn check_error(input: &str) -> Option<u32> {
    let input = input.trim();
    if input.is_empty() {
        print_error();
        return None;
    }
    let n = match input.parse::<u32>() {
        Ok(n) => n,
        Err(_) => {
            print_error();
            return None;
        },
    };
    if n > 5000 {
        print_error();
        return None;
    }
    Some(n)
}

fn display_help() {
    println!("USAGE");
    println!("    ./110borwein n");
    println!("\nDESCRIPTION");
    println!("    n  constant defining the integral to be computed");
}

fn borwein_product(x: f64, n: u32) -> f64 {
    let mut product = 1.0;
    let mut res;

    if x == 0.0 {
        return 1.0;
    }
    for k in 0..=n {
        res = x / (2 * k + 1) as f64;
        product *= res.sin() / res;
    }
    product
}

fn print_result(result: f64, n: u32) {
    println!("I{} = {:.10}", n, result);
    println!("diff = {:.10}", result - std::f64::consts::PI / 2.0);
}

fn midpoint_rule(n: u32) {
    let delta_x = INTERVAL_END / NUM_SUBINTERVALS;
    let mut sum = 0.0;
    let mut mid;

    for i in 0..NUM_SUBINTERVALS as u32 {
        mid = (i as f64 + 0.5) * delta_x;
        sum += borwein_product(mid, n);
    }
    let _  = sum * delta_x;
    println!("Midpoint rule:");
    print_result(sum * delta_x, n);
}

fn trapezoidal_rule(n: u32) {
    let delta_x = INTERVAL_END / NUM_SUBINTERVALS;
    let mut sum = 0.0;
    let mut mid;

    for i in 0..NUM_SUBINTERVALS as u32 {
        mid = i as f64 * delta_x;
        sum += borwein_product(mid, n);
    }
    let _  = (borwein_product(0.0, n) + borwein_product(INTERVAL_END, n)) / 2.0;
    println!("Trapezoidal rule:");
    print_result(sum * delta_x / 2.0, n);
}

fn main() {
    let mut input = String::new();

    loop {
        input.clear();
        print!("Enter the number of iterations: ");
        io::stdout().flush().unwrap();

        io::stdin().read_line(&mut input).unwrap();
        let input = input.trim();
        if input == "exit" {
            break;
        }
        if input == "-h" {
            display_help();
            continue;
        }
        if let Some(n) = check_error(input) {
            midpoint_rule(n);
            trapezoidal_rule(n);
        }
    }
}
