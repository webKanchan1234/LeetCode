/**
 * @param {string} s
 * @return {string}
 */
var smallestPalindrome = function(s) {
    let l=s.length;
    let freq={};
    for(const char of s){
        freq[char]=(freq[char]||0)+1;
    }

    let odd=0;
    let midd='';
    for(const char in freq){
        if(freq[char]%2!=0){
            odd++;
            midd=char;
        }
    }
    if(odd>1){
        return "Not Possisble";
    }
    const chars=Object.keys(freq).sort();
    let half = '';

    for (const char of chars) {
        const count = Math.floor(freq[char] / 2);
        half += char.repeat(count);
    }

    const palindrome = half + (odd === 1 ? midd : '') + half.split('').reverse().join('');
    return palindrome;
};