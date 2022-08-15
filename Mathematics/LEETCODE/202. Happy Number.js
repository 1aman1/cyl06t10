/**
 * @param {number} n
 * @return {boolean}
 */

var isHappy = function (n) {
    const lookup = new Map();

    while (true) {

        let sqSum = 0;
        let d1 = 0;

        while (n) {
            d1 = n % 10;
            sqSum += d1 * d1;
            n = Math.floor(n / 10);
        }

        if (sqSum === 1)
            return true;

        if (lookup.has(sqSum))
            return false;

        else {
            lookup.set(sqSum, true);
            n = sqSum;
        }
    }
};