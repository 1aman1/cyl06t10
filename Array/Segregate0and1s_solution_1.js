let arr = [1, 0, 0, 1, 1,];

function segregrate0and1(arr) {
    let left = 0, right = arr.length - 1;

    // WRONG logic
    // array stores value in 0,1,2,3,4..Nth manner,
    // where if left = 0, right = 4, then left < right is true, 
    // left > right is wrong
    console.log(left, ' ', right);

    while (left < right) {
        while (arr[left] == 1 && left < right)
            left++;
        while (arr[right] == 0 && left > right)
            right--;

        // same logic mistake here, left < right is correct
        // left > right is wron
        if (left < right) {
            arr[left] = 1;
            arr[right] = 0;
            left++;
            right--;
        }
        // console.log(arr[i]);
    }

    // MISSED
    // when a function executes, it's purpose is to solve a problem, and return the solution
    return arr;
}

console.log('array before', arr);

// since function returned an 'arr', we store it in a newarray 'newarr'
let newarr = segregrate0and1(arr)

console.log('array before', newarr);