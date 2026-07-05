function gcd(a, b) {
    if (b === 0) return a;
    else return gcd(b, a % b);
}

function lcm(a, b) {
    return a * b / gcd (a, b);
}

function solution(signals) {
    var total = [];
    var limit = 1;
    
    for (i = 0; i < signals.length; i++) {
        let [g, y, r] = signals[i];
        let sum = g + y + r;
        
        total.push([g, y, r, sum]);
        limit = lcm(limit, sum);
    }
    
    for (i = 1; i <= limit; i++) {
        var flag = 1;
        
        for (j = 0; j < total.length; j++)  {
            let [g, y, r, sum] = total[j];
            
            let cur = (i - 1) % sum + 1;
            
            if (g >= cur || cur > g + y) {
                flag = 0;
                break;
            }
        }
        
        if (flag) return i;
    }
    
    return -1;
}