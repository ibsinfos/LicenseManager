<?php
/**
 * Unreal Studio
 * Project: UnrealLicensing_v3_Release
 * User: jhollsoliver
 * Date: 25/06/15
 * Time: 14:41
 */
?>
<!--toastr-->
<link href="<?php echo ASSETS_URL;?>/toastr-master/toastr.css" rel="stylesheet" type="text/css" />
<script src="<?php echo ASSETS_URL;?>/toastr-master/toastr.js"></script>
<script>
    $(function () {
        toastr.options = {
            "closeButton": true,
            "debug": false,
            "progressBar": true,
            "positionClass": "toast-top-right",
            "onclick": null,
            "showDuration": "300",
            "hideDuration": "1000",
            "timeOut": "3000",
            "extendedTimeOut": "1000",
            "showEasing": "swing",
            "hideEasing": "linear",
            "showMethod": "fadeIn",
            "hideMethod": "fadeOut"
        };
    });

    function UpdatePwd()
    {

        var oldpass = $("#OldPwd").val();
        var newpass = $("#NewPwd").val();
        var newpass2 = $("#NewPwd2").val();

        $.ajax({

            type: "POST",
            data: {
                oldpass: oldpass,
                newpass: newpass,
                newpass2: newpass2,
                token:'<?php echo $TOTP->generateCode();?>',
                handler: 'changepwd'
            },

            url: "ajax/",
            dataType: "json",
            success: function (result) {

                if(result.status == 200)
                {
                    toastr[result.message.type](result.message.text, result.message.header);
                    $('#mdlChangePwd').modal('hide');
                }else{
                    $("#btnChangePwd").html('Update Password');
                    toastr[result.message.type](result.message.text, result.message.header);
                    //$("#btnChangePwd").removeClass('disabled');
                    $("#OldPwd").removeClass('spinner');
                    $("#NewPwd").removeClass('spinner');
                }


            },
            beforeSend: function () {

                $("#btnChangePwd").html('Checking...');
                //$("#btnChangePwd").addClass('disabled');
                $("#NewPwd").addClass('spinner');
                $("#OldPwd").addClass('spinner');

            },
            error: function () {
                //$("#btnChangePwd").removeClass('disabled');
                $("#OldPwd").removeClass('spinner');
                $("#NewPwd").removeClass('spinner');
                $("#btnChangePwd").html('Update Password');
                toastr['error']("Unknown Error. Contact the support team.", "Oops!");
            }
        });
    }


</script>