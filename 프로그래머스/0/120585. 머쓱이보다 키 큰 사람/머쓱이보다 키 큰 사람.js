function solution(array, height) {
    let arr = array.filter(a => a > height);
    
    return arr.length;
}