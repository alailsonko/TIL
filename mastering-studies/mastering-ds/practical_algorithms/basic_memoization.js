const times10 = (n) => {
    if (n === 0) return 0
    return n * 10 * 10
}

console.log('----------task 1----------------');
console.log('times10 returns:', times10(9));


const cache = {}

const memoTimes10 = (n) => {
    if (cache[n]) {
        console.log('fetching from cache', n);
        return cache[n]
    }
    console.log('calculating result');
    const result = times10(n)
    cache[n] = result
    return result
}


console.log('----------task 2----------------');
console.time('memoTimes10');
console.log('memoTimes10 calculated value returns:', memoTimes10(9));
console.timeEnd('memoTimes10');
console.time('memoTimes10');
console.log('memoTimes10 cached value returns:', memoTimes10(9));
console.timeEnd('memoTimes10');
