/**
 * @param {string} J
 * @param {string} S
 * @return {number}
 */
var numJewelsInStones = function(J, S) {
    let ret = 0;
    for (var j of J) {
        for (var s of S) {
            if (j === s) {
                ret++;
            }
        }
    }
    return ret;
};


//numJewelsInStones("aA", "aAAbbbb");
