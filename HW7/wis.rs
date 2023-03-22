use std::io;
use std::cmp::max;


fn main() {
    let mut buff = String::new();
    io::stdin().read_line(&mut buff).unwrap();

    let mut n_instances: usize = buff.trim().parse().unwrap();
    buff.clear();

    while n_instances > 0 {
        io::stdin().read_line(&mut buff).unwrap();
        let mut n_jobs: usize = buff.trim().parse().unwrap();
        buff.clear();

        let mut jobs: Vec<(i64, i64, i64)> = Vec::new();
        while n_jobs > 0 {
            io::stdin().read_line(&mut buff).unwrap();
            let job_input: Vec<i64> = buff.trim().split(" ")
                .map(|x| x.parse().unwrap())
                .collect();
            buff.clear();
            jobs.push((job_input[0], job_input[1], job_input[2]));
            n_jobs -= 1
        }

        jobs.sort_by(|a, b| (a.1).cmp(&b.1));
        jobs.insert(0, (0,0,0));
        
        let mut opt: Vec<i64> = vec![0];

        for j in 1..jobs.len() {
            //println!("jobs[j]: {} {} {}", jobs[j].0, jobs[j].1, jobs[j].2);
            let compatible = jobs[0..j].iter()
                .enumerate()
                .filter_map(|(index, x)| if x.1 <= jobs[j].0 { Some((index, x)) } else { None })
                .max_by(|(a, _), (b, _)| a.cmp(b));
            if let Some(x) = compatible {
                let i = x.0;
                //println!("jobs[{}]: {} {} {}", i, jobs[i].0, jobs[i].1, jobs[i].2);
                //println!("max(opt[{}], opt[{}] + {})", j-1, i, jobs[j].2);
                opt.push(max(opt[j-1], opt[i] + jobs[j].2));
            }
        }

        println!("{}", opt.last().unwrap());
        
        n_instances -= 1;
    }
}
