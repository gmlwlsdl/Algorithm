function solution(array) {
    const m = new Map();
    
    array.forEach((num) => {
        if (m.has(num)) {
            m.set(num, m.get(num) + 1);
        } else {
            m.set(num, 1);
        }
    })
    
    const max = Math.max(...m.values());
    var val = 0, cnt = 0;
    
    for(const [k, v] of m) {
        if (v === max) {
            cnt += 1;
            val = k;
        }
    }
    
    return cnt >= 2 ? -1 : val;
}