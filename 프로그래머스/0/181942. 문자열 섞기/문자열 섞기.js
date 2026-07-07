function solution(str1, str2) {
    let ans = '';
    
    for (i = 0; i < str2.length; i++) {
        if (isNaN(str1[i])) ans += str1[i];
        ans += str2[i];
    }
    
    return ans;
}