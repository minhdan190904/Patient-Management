document.addEventListener("DOMContentLoaded", function () {
    const emailForm = document.getElementById("email-form");
    const emailInput = document.getElementById("email");
    const emailError = document.getElementById("email-error");
    const emailSuccess = document.getElementById("email-success");

    emailForm.addEventListener("submit", function (e) {
        e.preventDefault();

        const emailValue = emailInput.value.trim();

        if (emailValue === "") {
            showError("Vui lòng nhập thông tin");
        } else if (!isValidEmail(emailValue)) {
            showError("Định dạng email sai, xin hãy nhập lại!");
        } else {
            showSuccessAndReload("Bạn đã gửi email thành công");
        }
    });

    function isValidEmail(email) {
        const emailRegex = /^[a-zA-Z0-9._-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4}$/;
        return emailRegex.test(email);
    }

    function showError(message) {
        emailError.textContent = message;
        emailError.style.display = "block";
        setTimeout(function () {
            emailError.style.display = "none";
        }, 2000);
    }

    function showSuccessAndReload(message) {
        // Sử dụng SweetAlert2 để hiển thị thông báo đẹp hơn
        Swal.fire({
            title: message,
            icon: 'success',
            timer: 2000, // Thời gian tự động đóng thông báo (2 giây)
            showConfirmButton: false,
        }).then(function () {
            // Sau khi thông báo đóng, tải lại trang
            location.reload();
        });
    }
});