let arr = [1, 0, 0, 1, 1]

console.log(arr)

for (let writer = 0, reader = 0; reader < arr.length; ++reader) {

    if (arr[reader] == 0) {
        continue;
    }

    arr[reader] = 0;
    arr[writer] = 1;
    ++writer;
}

console.log(arr)