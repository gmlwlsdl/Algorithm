function solution(my_string) {
    const n = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0];
    const arr = my_string.split('');
    var sum = 0;
    
    arr.forEach(a => {
        const aa = parseInt(a);
        if (!isNaN(aa) && n.includes(aa)) sum += aa;
    })
    
    return sum;
}