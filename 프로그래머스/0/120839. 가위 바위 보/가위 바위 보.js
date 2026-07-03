function solution(rsp) {
    const arr = [];
    
    [...rsp].forEach(h => {
        if (h === '2') arr.push(0);
        else if (h === '0') arr.push(5);
        else if (h === '5') arr.push(2);
    })
    
    return arr.join('');
}