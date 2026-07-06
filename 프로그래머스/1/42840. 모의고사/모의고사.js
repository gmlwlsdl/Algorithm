function solution(answers) {
    const one = [1, 2, 3, 4, 5];
    const two = [2, 1, 2, 3, 2, 4, 2, 5];
    const three = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5];
    let scores = [0, 0, 0];
    
    answers.forEach((a, i) => {
        if (a === one[i % one.length]) {
            scores[0]++;
        }
        if (a === two[i % two.length]) {
            scores[1]++;
        } 
        if (a === three[i % three.length]) {
            scores[2]++;
        }
    })
    
    let max = Math.max(...scores);
    let ans = [];
    
    scores.forEach((s, i) => {
        if (max === s) ans.push(i + 1);
    })
    
    return ans;
}