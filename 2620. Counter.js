var createCounter = function (n) {
    return () => {
        n++
        return n - 1
    }
};
