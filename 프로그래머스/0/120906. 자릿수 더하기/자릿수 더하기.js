function solution(n) {
    return String(n).split('').reduce((a, b) => a + parseInt(b), 0);
}