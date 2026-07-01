function cal(n, i) {
    return i % n === 0 ? i : '';
}

function solution(n, numlist) {
    return numlist.filter(x => cal(n, x));
}