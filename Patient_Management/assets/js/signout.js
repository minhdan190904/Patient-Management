function dangXuat(stringInput){
    var confirmation = confirm("Bạn có muốn đăng xuất với tư cách admin không?");
    if (confirmation) {
        window.location.href = stringInput;
        alert("Bạn đã đăng xuất thành công!");
    }
}