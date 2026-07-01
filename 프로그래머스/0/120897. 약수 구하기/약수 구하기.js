function solution(n) {
    const arr = new Array();
    
    for (i = 1; i < Math.sqrt(n); i++) {
        if (n % i === 0) {
            arr.push(i);
            arr.push(n / i);
        }
    }
    
    Number.isInteger(Math.sqrt(n)) ? arr.push(Math.sqrt(n)) : '';
    
    arr.sort((a, b) => a - b);
    
    return arr;
}