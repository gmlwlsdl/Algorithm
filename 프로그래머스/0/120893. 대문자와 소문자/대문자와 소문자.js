function solution(my_string) {
    let s = "";
    
    [...my_string].forEach((m) => {
        if (m === m.toUpperCase()) s += m.toLowerCase();
        else s += m.toUpperCase();
    })
    
    return s;
}