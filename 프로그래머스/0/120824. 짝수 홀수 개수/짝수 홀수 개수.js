function solution(num_list) {
    let cnt = 0;
    
    for (n of num_list) {
        if (n % 2 === 0) cnt += 1;
    }
    
    return [cnt, num_list.length - cnt];
}