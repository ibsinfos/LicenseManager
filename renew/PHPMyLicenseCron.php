<?php

/**
 * User: GiovannedeOliveira
 * Date: 02/09/2015
 * Time: 10:35
 */
include '../system/autoloader.php';
//include '../system/libs/PHPMailer-master/PHPMailerAutoload.php';
//include 'configs/config.php';
class PHPMyLicenseCron
{
    private $DatabaseHandler;
    private $PHPMailer;

    public function LoadLibrary($libname, $object)
    {
        $this->$libname = $object;
    }

    public function CheckForSuspensionDate()
    {
        $now = time();
        $sql = "SELECT id, expirydate FROM licenses WHERE status = 'active'";
        $query = $this->DatabaseHandler->query($sql);
        //$dump = $query->fetch_array();

        while($r = $query->fetch_array())
        {
            if($r['expirydate'] <= $now)
            {
                if(self::Suspend($r['id']))
                {
                    echo $r['id'].' Suspended. ';
                }else{
                    echo $r['id'].' failed to suspend. ';
                }

            }
        }

    }

    public function date_diff($begin, $end)
    {
        /*$datediff = $begin - $end;
        return floor($datediff/(60*60*24));*/
        $now = $begin; // or your date as well
        $your_date = $end;
        $datediff = $now - $your_date;
        $diference = abs(floor($datediff/(60*60*24)));
        return $diference;
    }

    public function Suspend($id)
    {
        $sql = "UPDATE licenses SET status = 'suspended' WHERE id = '$id'";
        $query = $this->DatabaseHandler->query($sql);
        if($query)
        {
            return true;
        }else{
            return false;
        }
    }

    public function SendSuspensionAlert($Mail, $days)
    {
        $sql = "SELECT * FROM licenses WHERE status = 'active'";
        $query = $this->DatabaseHandler->query($sql);
        //die(var_dump($query->fetch_array()));
        while($r = $query->fetch_array())
        {
            $dif = self::date_diff(time(), $r['expirydate']);
            //die($dif);
            if($dif < $days && $dif > -1)
            {
                $mail = $this->PHPMailer;



                $mail->isSMTP();                                      // Set mailer to use SMTP
                $mail->Host = $Mail['smtp_host'];  // Specify main and backup SMTP servers
                $mail->SMTPAuth = true;                               // Enable SMTP authentication
                $mail->Username = $Mail['smtp_user'];                 // SMTP username
                $mail->Password = $Mail['smtp_pass'];                           // SMTP password
                $mail->SMTPSecure = 'tls';                            // Enable TLS encryption, `ssl` also accepted
                $mail->Port = $Mail['smtp_port'];                                    // TCP port to connect to

                $mail->SMTPOptions = array(
                    'ssl' => array(
                        'verify_peer' => false,
                        'verify_peer_name' => false,
                        'allow_self_signed' => true
                    )
                );
                $mail->From = $Mail['mail_from'];
                $mail->FromName = $Mail['mail_from_name'];
                $mail->addAddress($r['customer_email']);

                $mail->isHTML(true);                                  // Set email format to HTML
                $mail->CharSet = 'UTF-8';
                $mail->Subject = 'Aviso de expiração de licença';

                switch($dif)
                {
                    case 1:
                        $dif = "Amanhã!";
                        break;
                    case 2:
                        $dif = "em dois dias!";
                        break;
                    case 3:
                        $dif = "em três dias!";
                        break;
                    case 4:
                        $dif = "em 4 dias!";
                        break;
                    case 5:
                        $dif = "em 5 dias!";
                        break;
                    case 6:
                        $dif = "em 6 dias!";
                        break;
                    case 7:
                        $dif = "em uma semana!";
                        break;
                    case 0:
                        $dif = "HOJE!";
                        break;
                }

                $search = array('{$product}', '{$expiryin}', '{$renewurl}', '{$host}', '{$licensekey}', '{$site_url}');
                $replace = array('FBNotificacao', $dif, BASE_URL.'/renew', $r['host'], $r['licensekey'], BASE_URL);
                $html = file_get_contents('configs/templates/expirealert.tpl');
                $html = str_replace($search, $replace, $html);
                $mail->Body    = $html;


                if(!$mail->send()) {
                    echo 'Message could not be sent. ';
                    echo 'Mailer Error: ' . $mail->ErrorInfo;
                } else {
                    echo 'OK, sended to: '.$r['customer_email'].' ';
                }
            }
        }
    }


}

$cron = new PHPMyLicenseCron();
$mail = new PHPMailer;
$cron->LoadLibrary('PHPMailer', $mail);
$cron->LoadLibrary('DatabaseHandler', $DatabaseHandler);
$cron->CheckForSuspensionDate();
//$cron->SendSuspensionAlert($Mail, 5);
