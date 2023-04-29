// function createvector(x, y, z) {
//     return {
//         x,
//         y,
//         z,

//         getLength() {
//             return Math.sqrt(this.x * this.x + this.y * this.y + this.z * this.z);
//         },

//         add(vector) {
//             return createvector(this.x + vector.x, this.y + vector.y, this.z + vector.z);
//         },

//         sub(vector) {
//             return createvector(this.x - vector.x, this.y - vector.y, this.z - vector.z);
//         },

//         product(number) {
//             return createvector(this.x * number, this.y * number, this.z * number);
//         },

//         scalarProduct(vector) {
//             return this.x * vector.x + this.y * vector.y + this.z * vector.z;
//         },

//         vectorProduct(vector) {
//             return createvector(
//                 this.y * vector.z - this.z * vector.y,
//                 this.z * vector.x - this.x * vector.z,
//                 this.x * vector.y - this.y * vector.x
//             );
//         },

//         toString(){
//             return `(${this.x}, ${this.y}, ${this.z})`;
//         }
//     }
// }

// let v1 = new createvector(10, 10, 10);
// let v2 = new createvector(4, 5, 6);
// let v3 = v1.vectorProduct(v2);
// console.log(v1.getLength());
// console.log(v3.toString());
// console.log(v1.x, v1.y, v1.z);

// const vectorPrototype = {
//     getLength() {
//         return Math.sqrt(this.x * this.x + this.y * this.y + this.z * this.z);
//     },
//     add(vector) {
//         return createvector(this.x + vector.x, this.y + vector.y, this.z + vector.z);
//     },
//     sub(vector) {
//         return createvector(this.x - vector.x, this.y - vector.y, this.z - vector.z);
//     },
//     product(number) {
//         return createvector(this.x * number, this.y * number, this.z * number);
//     },
//     scalarProduct(vector) {
//         return (this.x * vector.x + this.y * vector.y + this.z * vector.z);
//     },
//     vectorProduct(vector) {
//         return createvector(
//             this.y * vector.z - this.z * vector.y,
//             this.z * vector.x - this.x * vector.z,
//             this.x * vector.y - this.y * vector.x
//         )
//     },
//     toString(){
//         return `(${this.x}, ${this.y}, ${this.z})`;
//     }
// }

// function createvector(x, y, z) {
//     const vector = { x, y, z };
//     Object.setPrototypeOf(vector, vectorPrototype);
//     return vector;
// }

// let v1 = new createvector(10, 10, 10);
// let v2 = new createvector(4, 5, 6);
// let v3 = v1.vectorProduct(v2);
// console.log(v3);

class Vector {
    constructor(x, y, z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    get length() {
        return Math.sqrt(this.x * this.x + this.y * this.y + this.z * this.z);
    }

    add(vector) {
        return new Vector(this.x + vector.x, this.y + vector.y, this.z + vector.z);
    }

    sub(vector) {
        return new Vector(this.x - vector.x, this.y - vector.y, this.z - vector.z);
    }

    product(number) {
        return new Vector(this.x * number, this.y * number, this.z * number);
    }

    scalarProduct(vector) {
        return this.x * vector.x + this.y * vector.y + this.z * vector.z;
    }

    vectorProduct(vector) {
        return new Vector(this.y * vector.z - this.z * vector.y,
            this.z * vector.x - this.x * vector.z,
            this.x * vector.y - this.y * vector.x);
    }

    toString() {
        return "(" + this.x + ";" + this.y + ";" + this.z + ")";
    }
}

let v1 = new Vector(10, 10, 10);
let v2 = new Vector(4, 5, 6);
let v3 = v1.vectorProduct(v2);
console.log(v3);