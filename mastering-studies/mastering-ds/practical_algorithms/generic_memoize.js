const times10 = (n) => (n * 10)

const memoize = (fn) => {

}

const memoizedTimes10 = memoize(times10)

console.log('---------------task4-----------------');
try {
    console.log('task 4 calculated value:', memoizedTimes10(9));
    console.log('task 4 cached value:', memoizedTimes10(9));
} catch (error) {
    console.error('task4:', error);
}