function solution(n) {
    const arr = new Array();
    
    for (i = 0; i <= n; i++) {
        if (i % 2 != 0) arr.push(i);
    }
    
    return arr;
}