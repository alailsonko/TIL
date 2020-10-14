/**
 * Problem
 * 
 * The counting valleys challenge is counting the number of valleys
 * gary the hiker goes though:
 * 
 *  * gary = hiker
 *  * sea level is 0 --- also the starting level
 *  * S = descriptive string that is the path of steps gary the hiker takes
 *  * U and D are "Up" and "Down" respectively and the direction of Garys step
 *  * N = number of steps between 2 and 10^6 (1,000,000)
 *  * AR is a single string of spaced numbers with values randing between 1 and 100 ---
 *   ex 10 11 20 31
 *  * N is the number of values in steps in the path between 2 and 1000000(which
 *   could be useless if we're just calculating the array length)
 *  * A valley is defined as going lower than sea level and then back to sea level
 */

//  example

// counting the values of the path (s)
// function countingValleys(n, s) {
//     //setting the constrains
//     const min = 2;
//     const max = 1000000
    
//     // if its a string convert it to an array
//     // ex "UDU" = ["U", "D", "U"]
//     s = (type ar === "string") ? s.split('') : s;
    
//     // check if s meets the requirements
//     if(s.length >= min && s.length <= max) {
//         // continue
//     }
// }

// validating N

function countingValleys(n, s) {
    // setting the constraints
    const min = 2;
    const max = 1000000;
    let valleys = 0;
    let isInValley = false;  
    
    // if it's a string convert it to an array
    // ex "UDU" = ["U", "D", "U"]    
    s = (typeof s === "string") ? s.split('') : s;
    // ["U", "D", "D", "D", "U", "D", "U", "U"] 

    // check if s meets the requirements
    if (s.length >= min
         && s.length <= max
         && n === parseInt(n, 0)
         && n >= min
         && n <= max 
         && n === s.length) {
         
         // converting the array steps to integers
         s = s.map(steps => ((steps === "U") ? 1 : -1));
         // [1, -1, -1, -1, 1, -1, 1, 1]
         
         let path = 0;
         for(let i in s) {
              path += s[i];
              if (path < 0 && !isInValley) {
                   // to check that we're not already in a valley 
                   // start of a valley
                   isInValley = true; 
              }
              if (path == 0 && isInValley) {
                   // to check if we're just coming out of a valley
                   // end of valley, increase count
                   valleys++; // increase count
                   isInValley = false; // reset isInValley
              }    
         } 

         //  0 +  1 =  1 (Moved up = valley not started)
         //  1 + -1 =  0 (Back to sea level = valley not started)
         //  0 + -1 = -1 (Below sea level = valley started)
         // -1 + -1 = -2 (Moved lower = still in valley
         // -2 +  1 = -1 (Moved up = still in valley)
         // -1 + -1 = -2 (Moved lower = still in valley)
         // -2 +  1 = -1 (Moved up = still in valley)
         // -1 +  1 =  0 (Back to sea level = 1 valley)
         // initial = 0
         // end = 0
    }
        console.log(path)
         console.log(s)
         console.log(isInValley)
    // to make sure we return even when the req. are not met
    return valleys;
}


const n = 7
const s = "UDDUDUU"

console.log(countingValleys(n, s))