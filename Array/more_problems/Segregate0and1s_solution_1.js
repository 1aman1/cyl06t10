let arr = [1, 0, 0, 1, 1,];

function segregrate0and1(arr) {
    let left = 0, right = arr.length - 1;

    while (left < right) {
        while (arr[left] == 1 && left < right)
            left++;
        while (arr[right] == 0 && left > right)
            right--;

        if (left < right) {
            arr[left] = 1;
            arr[right] = 0;
            left++;
            right--;
        }
    }

    return arr;
}

console.log('array before', arr);

// since function returned an 'arr', we store it in a newarray 'newarr'
let newarr = segregrate0and1(arr)

console.log('array before', newarr);