const times10 = (n) =>  (n * 10)

const memoizedClosureTimes10 = () => { 
   let cache = {}
   return (n) => {
       if (cache[n]) {
           console.log('fetching from cache', n);
           return cache[n]
       }
       console.log('calculating result');
       const result = times10(n)
       cache[n] = result
       return result
   }
}


const memoClosureTimes10 = memoizedClosureTimes10()
console.log('------------task 3----------------');

try {
    console.log('task 3 calculated value:', memoClosureTimes10(9));    
    console.log('task 3 cached value:', memoClosureTimes10(9));    
} catch (error) {
    console.log(error);
}
