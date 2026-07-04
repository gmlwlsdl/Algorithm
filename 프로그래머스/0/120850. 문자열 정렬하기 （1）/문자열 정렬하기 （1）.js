function solution(my_string) {
    let arr = [...my_string].filter(m => !isNaN(m)).map((m) => Number(m));
    
    return arr.sort((a,b) => a- b);
}