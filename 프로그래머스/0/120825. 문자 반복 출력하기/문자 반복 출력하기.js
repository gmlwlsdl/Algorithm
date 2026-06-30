function solution(my_string, n) {
    return [...my_string].reduce((a, c) => a + c.repeat(n), '');
}