// http://www.webhek.com/color-test
// 一直运行吧少年！如果不怕卡爆浏览器自己加个while (true)，23333
var childs = document.getElementById('box').childNodes;
console.log(childs.length);
var round = Math.sqrt(childs.length);
console.log(round);
var style0 = childs[0].style.backgroundColor;
var style1 = childs[1].style.backgroundColor;
var style2 = childs[2].style.backgroundColor;
if (style0 === style1 && style0 === style2) {
  for (var i = 3; i < childs.length; i++) {
    var color = childs[i].style.backgroundColor;
    if (color !== style0) {
      var row = Math.floor(i / round) + 1;
      var col = i % round + 1;
      console.log(row + ":" + col);
      console.log(color);
      childs[i].click();
    }
  }
} else {
  if (style1 === style2) {
    console("1 : 1");
    console.log(style0);
    childs[0].click();
  } else if (style0 === style2) {
    console("1 : 2");
    console.log(style1);
    childs[1].click();
  } else if (style0 === style1) {
    console("1 : 2");
    console.log(style2);
    childs[2].click();
  }
}

