var header = document.getElementById('header');
var mobileMenu = document.getElementById('mobile-menu-btn');

mobileMenu.onclick = function(){
var isClosed = header.clientHeight === 46;
    if(isClosed){
        header.style.height = 'auto';
    } else{
        header.style.height = '46px';
    }
}
var menuItems = document.querySelectorAll('#nav li a');
for(var i = 0; i < menuItems.length; i++){
    var menuItem = menuItems[i];

    menuItem.onclick = function(){
        var isParentMenu = this.nextElementSibling && menuItem.nextElementSibling.classList.contains('subnav');
       if(!isParentMenu) header.style.height = null;
    }
}

