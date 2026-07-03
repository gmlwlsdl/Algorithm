const fs = require('fs').readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt").toString().trim();

let l = "";

for (i = 0; i < fs; i++) {
    l += "*";
    console.log(l);
}
