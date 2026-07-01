function solution(strlist) {
    const arr = new Array();
    
    strlist.forEach((s) => {
        arr.push(s.length);
    })
    
    return arr;
}