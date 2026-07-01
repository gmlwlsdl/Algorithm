function solution(my_string) {
    const v = ['a', 'e', 'i', 'o', 'u'];
    return my_string.split('').filter((s) => !v.includes(s)).join('');
}