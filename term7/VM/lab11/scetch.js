function f(x, y, z) {
    return [z, x**2];
}

function rungeKutta(f, x0, y0, z0, h, n) {
    let x = [x0];
    let y = [y0];
    let z = [z0];

    for (let i = 1; i <= n; i++) {
        let [k1y, k1z] = f(x[i-1], y[i-1], z[i-1]);
        let [k2y, k2z] = f(x[i-1] + h/2, y[i-1] + h/2 * k1y, z[i-1] + h/2 * k1z);
        let [k3y, k3z] = f(x[i-1] + h/2, y[i-1] + h/2 * k2y, z[i-1] + h/2 * k2z);
        let [k4y, k4z] = f(x[i-1] + h, y[i-1] + h * k3y, z[i-1] + h * k3z);

        let nextY = y[i-1] + h/6 * (k1y + 2*k2y + 2*k3y + k4y);
        let nextZ = z[i-1] + h/6 * (k1z + 2*k2z + 2*k3z + k4z);

        y.push(nextY);
        z.push(nextZ);

        let nextX = x[i-1] + h;
        x.push(nextX);
    }

    return {x, y};
}

// Заданные параметры для h = 0.1
let x0 = 0;
let y0 = 1;
let z0 = 0;
let h = 0.1;
let n = 10;

let solution1 = rungeKutta(f, x0, y0, z0, h, n);

// Заданные параметры для h = 0.01
h = 0.01;
n = 100;

let solution2 = rungeKutta(f, x0, y0, z0, h, n);
console.log(solution1);
console.log(solution2)
