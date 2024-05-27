document.getElementById('loginForm').addEventListener('submit', function (e) {
    e.preventDefault();

    var username = document.getElementById('usernameInput').value;
    var password = document.getElementById('passwordInput').value;

    if (!username || !password) {
        Swal.fire({
            icon: 'error',
            title: 'Lỗi',
            text: 'Vui lòng nhập tài khoản và mật khẩu.'
        });
    } else {
            Swal.fire({
                icon: 'success',
                title: 'Đăng nhập thành công',
                text: 'Chào mừng bạn, Bác sĩ!'
            }).then(function() {
                window.location.href = '../logged-html/trangchu.html';
            });
    }
});