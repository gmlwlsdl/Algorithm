function solution(a, b) {
    var answer = 0;
    return Math.max(a.toString()+b.toString(), 2 * (a.toString()*b.toString()));
}