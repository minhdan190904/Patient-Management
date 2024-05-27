function checkDate(dateString) {
    var datePattern = /^\d{4}-\d{2}-\d{2}$/;
    return datePattern.test(dateString);
  }
        var patients = [];
        var addPatientButton = document.getElementById("addPatientButton");
        var patientForm = document.getElementById("patientForm");
        var patientNameInput = document.getElementById("patientName");
        var patientDOBInput = document.getElementById("patientDOB");
        var patientLocationInput = document.getElementById("patientLocation");
        var patientReasonInput = document.getElementById("patientReason");
        var patientDiagnosisInput = document.getElementById("patientDiagnosis");
        var patientAdmissionDateInput = document.getElementById("patientAdmissionDate");
        var patientCurrentStatusInput = document.getElementById("patientCurrentStatus");
        var patientPhoneNumberInput = document.getElementById("patientPhoneNumber");
        var patientImageInput = document.getElementById("patientImage");
        var patientList = document.getElementById("patientList");
        var h1Element = document.getElementById('numberRoom');
        if (h1Element) {
       var pageTitle = h1Element.textContent;
       var roomNumberMatch = pageTitle.match(/\d+/);
       if (roomNumberMatch) {
        var roomNumber = roomNumberMatch[0];
        var keyS = "patients" + roomNumber;
       }
}
    
        // Bắt sự kiện khi nhấn nút "Thêm bệnh nhân"
        addPatientButton.addEventListener("click", function() {
          // Lấy giá trị nhập vào từ các trường input
  var patientName = patientNameInput.value;
  var patientDOB = patientDOBInput.value;
  var patientLocation = patientLocationInput.value;
  var patientReason = patientReasonInput.value;
  var patientDiagnosis = patientDiagnosisInput.value;
  var patientAdmissionDate = patientAdmissionDateInput.value;
  var patientCurrentStatus = patientCurrentStatusInput.value;
  var patientPhoneNumber = patientPhoneNumberInput.value;
  var patientImageFile = patientImageInput.files[0];
  
  if (patientName.trim() === "") {
    alert("Vui lòng nhập tên bệnh nhân.");
    return;
  }

  var regex = /^[\p{L}\s']+$/u;

if (!regex.test(patientName)) {
    alert("Tên bệnh nhân không hợp lệ.");
    return;
}
  
  if (patientDOB.trim() === "") {
    alert("Thông tin ngày sinh chưa được nhập hoặc lỗi logic.");
    return;
  }
  
  if (patientLocation.trim() === "") {
    alert("Vui lòng nhập địa điểm.");
    return;
  }
  
  if (patientReason.trim() === "") {
    alert("Vui lòng nhập lý do nhập viện.");
    return;
  }
  
  if (patientDiagnosis.trim() === "") {
    alert("Vui lòng nhập chuẩn đoán.");
    return;
  }
  
  if (patientAdmissionDate.trim() === "") {
    alert("Thông tin ngày nhập viện chưa được nhập hoặc lỗi logic.");
    return;
  }
  
  if (patientPhoneNumber.trim() === "") {
    alert("Vui lòng nhập số điện thoại.");
    return;
  }
  
  if (!/^\d+$/.test(patientPhoneNumber) || patientPhoneNumber.length != 10) {
    alert("Số điện thoại sai định dạng (có đúng 10 số)");
    return;
  }
  if (!patientImageFile) {
    alert("Vui lòng chọn một tệp hình ảnh.");
    return;
  }
    
          // Tạo một đối tượng bệnh nhân mới (kieu class c++ struct)
          var newPatient = {
            name: patientName,
            dob: patientDOB,
            location: patientLocation,
            reason: patientReason,
            diagnosis: patientDiagnosis,
            admissionDate: patientAdmissionDate,
            currentStatus: patientCurrentStatus,
            phoneNumber: patientPhoneNumber,
            image: URL.createObjectURL(patientImageFile)
          };
    
          // Thêm bệnh nhân vào danh sách bệnh nhân
          patients.push(newPatient);
    
          // Lưu danh sách bệnh nhân vào Local Storage
          localStorage.setItem(keyS, JSON.stringify(patients)); // khi load lai web se ko bi mat du lieu
    
          // Hiển thị thông tin bệnh nhân trong danh sách
          var patientDiv = document.createElement("div");
          patientDiv.innerHTML = '<div class="container-info">' + '<div class="patient-image">' + 
    '<img class="inline-info" src="' + newPatient.image + '" alt="Ảnh bệnh nhân">'  + '<div class="inline-info th">' +
    "<strong>Trạng thái: </strong>" + newPatient.currentStatus + '</div>' +
    '</div>' + '<div class="patient-thongtin inline-info">' +
    "<strong>Tên:</strong> " + newPatient.name + "<br>" +
    "<strong>Ngày sinh:</strong> " + newPatient.dob + "<br>" +
    "<strong>Quê quán:</strong> " + newPatient.location + "<br>" +
    "<strong>Lí do khám bệnh:</strong> " + newPatient.reason + "<br>" +
    "<strong>Chuẩn đoán bệnh:</strong> " + newPatient.diagnosis + "<br>" +
    "<strong>Ngày nhập viện:</strong> " + newPatient.admissionDate + "<br>" +
    "<strong>Số điện thoại:</strong> " + newPatient.phoneNumber + "<br>" +
    '</div>' + '</div>' +
    '<button onclick="editPatient(' + (patients.length - 1) + ')">Chỉnh sửa</button>' +
    '<button class="dele-but" onclick="deletePatient(' + (patients.length - 1) + ')">Xóa</button>';
    
          // Thêm thẻ div bệnh nhân vào danh sách bệnh nhân
          patientList.appendChild(patientDiv);
    
          // Xóa nội dung trong các trường input
          patientNameInput.value = "";
          patientDOBInput.value = "";
          patientLocationInput.value = "";
          patientReasonInput.value = "";
          patientDiagnosisInput.value = "";
          patientAdmissionDateInput.value = "";
          patientCurrentStatusInput.value = "";
          patientPhoneNumberInput.value = "";
          patientImageInput.value = "";
          alert("Đã thêm bệnh nhân!");
        });
    
        // Hàm để tải danh sách bệnh nhân từ Local Storage khi trang web được tải lại
        function loadPatientsFromLocalStorage() {
          var storedPatients = localStorage.getItem(keyS);
          if (storedPatients) {
            patients = JSON.parse(storedPatients);
    
            // Hiển thị danh sách bệnh nhân từ Local Storage
            for (var i = 0; i < patients.length; i++) {
              var patient = patients[i];
              var patientDiv = document.createElement("div");
              patientDiv.innerHTML = '<div class="container-info">' + '<div class="patient-image">' + 
              '<img class="inline-info" src="' + patient.image + '" alt="Ảnh bệnh nhân">'  + '<div class="inline-info th">' +
              "<strong>Trạng thái: </strong> " + patient.currentStatus + '</div>' +
              '</div>' + '<div class="patient-thongtin inline-info">' +
              "<strong>Tên:</strong> " + patient.name + "<br>" +
              "<strong>Ngày sinh:</strong> " + patient.dob + "<br>" +
              "<strong>Quê quán:</strong> " + patient.location + "<br>" +
              "<strong>Lí do khám bệnh:</strong> " + patient.reason + "<br>" +
              "<strong>Chuẩn đoán bệnh:</strong> " + patient.diagnosis + "<br>" +
              "<strong>Ngày nhập viện:</strong> " + patient.admissionDate + "<br>" +
              "<strong>Số điện thoại:</strong> " + patient.phoneNumber + "<br>" +
              '</div>' + '</div>'  +
                '<button onclick="editPatient(' + i + ')">Chỉnh sửa</button>' +
                '<button class="dele-but" onclick="deletePatient(' + i + ')">Xóa</button>';
              patientList.appendChild(patientDiv);
            }
          }
        }
        // Gọi hàm để tải danh sách bệnh nhân từ Local Storage khi trang web được tải lại
        loadPatientsFromLocalStorage();
   // Hàm để chỉnh sửa thông tin bệnh nhân
        function editPatient(index) {
    var patient = patients[index];
    var choice = prompt("Chọn thông tin bạn muốn chỉnh sửa (chọn số từ 1 -> 9):\n1. Tên\n2. Ngày sinh\n3. Quê quán\n4. Lí do khám bệnh\n5. Chuẩn đoán bệnh\n6. Ngày nhập viện\n7. Trạng thái\n8. Số điện thoại\n9. Hình ảnh");
    switch (choice) {
      case "1":
        var updatedName = prompt("Nhập tên mới:", patient.name);
        if (updatedName !== null && updatedName !== "") {
          var regex = /^[\p{L}\s']+$/u;
          if (!regex.test(updatedName)) {
            alert("Tên bệnh nhân không hợp lệ.");
        } else {
          patient.name = updatedName;
          alert("Đã cập nhật thông tin.");
        }
        }
        break;
      case "2":
        var updatedDOB = prompt("Nhập ngày sinh mới (đúng định dạng yyyy-mm-dd):", patient.dob);
        if (updatedDOB !== null && updatedDOB !== "") {
          if(checkDate(updatedDOB)){
              patient.dob = updatedDOB;
              alert("Đã cập nhật thông tin.");
          } else{
              alert("Sai định dạng yyyy-mm-dd.");
          }
        }
        break;
      case "3":
        var updatedLocation = prompt("Nhập quê quán mới:", patient.location);
        if (updatedLocation !== null && updatedLocation !== "") {
          patient.location = updatedLocation;
          alert("Đã cập nhật thông tin.");
        }
        break;
      case "4":
        var updatedReason = prompt("Nhập lí do khám bệnh mới:", patient.reason);
        if (updatedReason !== null && updatedReason !== "") {
          patient.reason = updatedReason;
          alert("Đã cập nhật thông tin.");
        }
        break;
      case "5":
        var updatedDiagnosis = prompt("Nhập chuẩn đoán bệnh mới:", patient.diagnosis);
        if (updatedDiagnosis !== null && updatedDiagnosis !== "") {
          patient.diagnosis = updatedDiagnosis;
          alert("Đã cập nhật thông tin.");
        }
        break;
      case "6":
        var updatedAdmissionDate = prompt("Nhập ngày nhập viện mới (đúng định dạng yyyy-mm-dd):", patient.admissionDate);
        if (updatedAdmissionDate !== null && updatedAdmissionDate !== "") {
          if(checkDate(updatedAdmissionDate)){
              patient.admissionDate = updatedAdmissionDate;
              alert("Đã cập nhật thông tin.");
          } else{
              alert("Sai định dạng yyyy-mm-dd.");
          }
      }
        break;
      case "7":
        var updatedCurrentStatus = prompt("Nhập tình trạng bệnh hiện tại mới:", patient.currentStatus);
        if (updatedCurrentStatus !== null && updatedCurrentStatus !== "") {
          patient.currentStatus = updatedCurrentStatus;
          alert("Đã cập nhật thông tin.");
        }
        break;
      case "8":
        var updatedPhoneNumber = prompt("Nhập số điện thoại mới:", patient.phoneNumber);
        if (updatedPhoneNumber !== null) {
          if (/^\d+$/.test(updatedPhoneNumber) && updatedPhoneNumber.length == 10) {
            patient.phoneNumber = updatedPhoneNumber;
            alert("Đã cập nhật thông tin.");
          } else {
            alert("Số điện thoại sai định dạng (có đúng 10 số).");
          }
        }
        break;
            case "9":
              // Bắt sự kiện khi người dùng nhấn nút "Chọn hình ảnh" để cập nhật lại hình ảnh
              var updatedImageInput = document.createElement("input");
              updatedImageInput.type = "file";
              updatedImageInput.accept = "image/*";
              updatedImageInput.style.display = "none";
    
              updatedImageInput.addEventListener("change", function() {
                var updatedImageFile = updatedImageInput.files[0];
                if (updatedImageFile) {
                  patient.image = URL.createObjectURL(updatedImageFile);
    
                  // Cập nhật hiển thị trên giao diện
                  var patientDiv = patientList.children[index];
                  var imgElement = patientDiv.querySelector("img");
                  imgElement.src = patient.image;
    
                  // Lưu lại thông tin đã chỉnh sửa vào Local Storage
                  localStorage.setItem(keyS, JSON.stringify(patients));
                  alert("Đã cập nhật thông tin.");
                }
              });
    
              updatedImageInput.click();
              break;
            default:
              alert("Lựa chọn không hợp lệ.");
              return;
          }
          // Cập nhật hiển thị trên giao diện
          var patientDiv = patientList.children[index];
          patientDiv.innerHTML = '<div class="container-info">' + '<div class="patient-image">' + 
          '<img class="inline-info" src="' + patient.image + '" alt="Ảnh bệnh nhân">'  + '<div class="inline-info th">' +
          "<strong>Trạng thái: </strong> " + patient.currentStatus + '</div>' +
          '</div>' + '<div class="patient-thongtin inline-info">' +
          "<strong>Tên:</strong> " + patient.name + "<br>" +
          "<strong>Ngày sinh:</strong> " + patient.dob + "<br>" +
          "<strong>Quê quán:</strong> " + patient.location + "<br>" +
          "<strong>Lí do khám bệnh:</strong> " + patient.reason + "<br>" +
          "<strong>Chuẩn đoán bệnh:</strong> " + patient.diagnosis + "<br>" +
          "<strong>Ngày nhập viện:</strong> " + patient.admissionDate + "<br>" +
          "<strong>Số điện thoại:</strong> " + patient.phoneNumber + "<br>" +
           '</div>' + '</div>'  +
                '<button onclick="editPatient(' + index + ')">Chỉnh sửa</button>' +
                '<button class="dele-but" onclick="deletePatient(' + index + ')">Xóa</button>';
    
          // Lưu lại thông tin đã chỉnh sửa vào Local Storage
          localStorage.setItem(keyS, JSON.stringify(patients));
        }
    
        // Hàm để xóa bệnh nhân khỏi danh sách
        function deletePatient(index) {
          var confirmDelete = confirm("Bạn có chắc chắn muốn xóa bệnh nhân này khỏi dữ liệu phòng " + roomNumber + "?");
          if (confirmDelete) {
            patients.splice(index, 1);
    
            // Xóa thẻ div bệnh nhân tương ứng
            var patientToDelete = patientList.children[index];
            patientList.removeChild(patientToDelete);
    
            // Cập nhật lại giá trị index của các nút xóa và sửa
            var allPatientDivs = patientList.children;
            for (var i = 0; i < allPatientDivs.length; i++) {
              var patientDiv = allPatientDivs[i];
              var editButton = patientDiv.querySelector("button[onclick^='editPatient']");
              var deleteButton = patientDiv.querySelector("button[onclick^='deletePatient']");
              
              // Cập nhật giá trị index cho nút xóa và sửa
              if (editButton) {
                editButton.setAttribute("onclick", "editPatient(" + i + ")");
              }
              if (deleteButton) {
                deleteButton.setAttribute("onclick", "deletePatient(" + i + ")");
              }
            }
    
            // Lưu lại danh sách đã cập nhật vào Local Storage
            localStorage.setItem(keyS, JSON.stringify(patients));
          }
        }