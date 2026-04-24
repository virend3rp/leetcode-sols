// Last updated: 4/24/2026, 10:14:03 PM
function isAnagram(str1, str2) {
  if (str1.length !== str2.length) {
    return false;
  }
  let obj = {};
  for (let i = 0; i < str1.length; i++) {
    if (obj[str1[i]]) {
      obj[str1[i]] += 1;
    } else {
      obj[str1[i]] = 1;
    }
  }
  for (let i = 0; i < str2.length; i++) {
    if (obj[str2[i]]) {
      obj[str2[i]] -= 1;
    } else {
      return false;
    }
  }
  for (let key in obj) {
    if (obj[key] !== 0) {
      return false;
    }
  }
  return true;
}

