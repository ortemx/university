function aitken(x, y, targetX) {
    let n = x.length;
    let q = new Array(n).fill(0).map(() => new Array(n).fill(0));

    for (let i = 0; i < n; i++) {
        q[i][0] = y[i];
    }

    for (let i = 1; i < n; i++) {
        for (let j = 1; j <= i; j++) {
            if (Math.abs(q[i][j] - q[i][j-1]) < 0.001) {
                return q[i][j];
            }
            q[i][j] = ((targetX - x[i - j]) * q[i][j - 1] - (targetX - x[i]) * q[i - 1][j - 1]) / (x[i] - x[i - j]);
        }
    }
    printArray(q)
    return q[n - 1][n - 1];
}

function printArray(array) {
    output = "";
    for (let i = 0; i < array.length; i++) {
        let str = "";
        for(let j = 0; j < array[i].length; j++) {
            str += (array[i][j].toFixed(4)) + " | "
        }
        output += str + "\n"
    }
    console.log(output)
}

let targetX = 1.43
let value = aitken(
    [1, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2],
    [2.7182, 3.0041, 3.3201, 3.6692, 4.0552, 4.4816, 4.9530, 5.4739, 6.0496, 6.6858, 7.3890],
    targetX)

console.log(value)
console.log(Math.abs(value - Math.exp(targetX)))