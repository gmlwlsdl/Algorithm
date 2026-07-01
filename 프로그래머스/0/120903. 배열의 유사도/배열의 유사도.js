function solution(s1, s2) {
    let cnt = 0;
    
    s1.forEach(s => {
        if (s2.includes(s)) cnt += 1;
    })
    
    return cnt;
}