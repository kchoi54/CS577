use std::io;
fn dfs(graph: &mut Vec<Vec<i32>>, s: usize, t: usize, visited: &mut Vec<bool>, flow: i32) -> i32 {
    visited[s] = true;
    if s == t {
        return flow;
    }
    for i in 0..graph.len() {
        if !visited[i] && graph[s][i] > 0 {
            let new_flow = flow.min(graph[s][i]);
            let returned_flow = dfs(graph, i, t, visited, new_flow);
            if returned_flow > 0 {
                graph[s][i] -= returned_flow;
                graph[i][s] += returned_flow;
                return returned_flow;
            }
        }
    }
    return 0;
}

fn max_flow(graph: &mut Vec<Vec<i32>>, s: usize, t: usize) -> i32 {
    let mut max_flow = 0;
    loop {
        let mut visited = vec![false; graph.len()];
        let flow = dfs(graph, s, t, &mut visited, std::i32::MAX);
        if flow == 0 {
            break;
        }
        max_flow += flow;
    }
    return max_flow;
}



fn main() {
    let mut buff = String::new();
    io::stdin().read_line(&mut buff).unwrap();

    let n_instances = buff.trim().parse().unwrap();
    buff.clear();

    for _ in 0..n_instances {
        io::stdin().read_line(&mut buff).unwrap();
        let size: Vec<usize> = buff.trim().split(" ")
                .map(|x| x.parse().unwrap())
                .collect();
        buff.clear();

        let vector_len = size[0] + size[1] + 2;
        let mut graph = vec![vec![0; vector_len]; vector_len];

        for i in 1..size[0]+1 {
            graph[0][i] = 1;
        }

        for i in 0..size[1] {
            graph[size[0]+1+i][vector_len-1] = 1
        }

        for _ in 0..size[2] {
            io::stdin().read_line(&mut buff).unwrap();
            let e: Vec<usize> = buff.trim().split(" ")
                .map(|x| x.parse().unwrap())
                .collect();
            buff.clear();

            graph[e[0]][e[1]+size[0]] = 1
        }

        let f: i32 = max_flow(&mut graph, 0, vector_len-1);
        println!("{} {}", f, if f == size[1] as i32 && f == size[0] as i32 {"Y"} else {"N"});
    }
}