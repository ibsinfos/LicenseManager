<?php

$config = array(
    'title' => 'PHPMyLicense Setup Wizard',
    'description' => 'This wizard will guide you through the installation process',

    'wizard_file' => 'index.php',

    'copyright' => '<a href="http://phpmylicense.ml/" target="_blank">PHPMyLicense</a> &copy; '.date('Y'),

    'show_steps' => true,
    'show_back_button' => true,

    'view' => 'default',
    'language' => 'en',

    'db_type' => 'mysqli',
    'db_show_queries' => true,
    'db_charset' => 'utf8',
    'db_collation' => 'utf8_general_ci',
);
