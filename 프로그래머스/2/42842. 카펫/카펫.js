function solution(brown, yellow) {
    let len = brown + yellow;
    
    for (i = 3; i <= Math.sqrt(len); i++) {
        if (len % i === 0) {
            const h = len / i;
            
            if ((i - 2) * (h - 2) === yellow) {
                let arr = [i, h];
                arr.sort((a, b) => b - a);
                
                return arr;
            }
        }
    }
}