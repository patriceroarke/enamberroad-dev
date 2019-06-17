<?php
/**
 * @file
 * Code for the Blocks feature.
 */

function amberroad_blocks_configuration() {
  $form['social'] = array(
    '#type' => 'fieldset',
    '#title' => t('Social Platforms'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['career'] = array(
    '#type' => 'fieldset',
    '#title' => t('Careers Mail Id'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['promo_text'] = array(
    '#type' => 'fieldset',
    '#title' => t('Homepage Promo Text'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['social']['amberroad_blocks_linkedin_page'] = array(
    '#title' => t('Linkedin Url'),
    '#type' => 'textfield',
    '#default_value' => variable_get('amberroad_blocks_linkedin_page', 'http://www.linkedin.com/groupInvitation?groupID=2374608&amp;sharedKey=1A2F3F6276F1'),
  );
  $form['social']['amberroad_blocks_twitter_page'] = array(
    '#title' => t('Twitter Url'),
    '#type' => 'textfield',
    '#default_value' => variable_get('amberroad_blocks_twitter_page', 'http://twitter.com/GTMBestPractice'),
  );
  $form['social']['amberroad_blocks_youtube_page'] = array(
    '#title' => t('Youtube Url'),
    '#type' => 'textfield',
    '#default_value' => variable_get('amberroad_blocks_youtube_page', 'http://www.youtube.com/user/GTMBestPractices'),
  );
  $form['social']['amberroad_blocks_blog_page'] = array(
    '#title' => t('Blogs Url'),
    '#type' => 'textfield',
    '#default_value' => variable_get('amberroad_blocks_blog_page', 'http://www.amberroad.com/html/rl_blogs.shtml'),
  );
  $form['social']['amberroad_blocks_facebook_page'] = array(
    '#title' => t('Facebook Url'),
    '#type' => 'textfield',
    '#default_value' => variable_get('amberroad_blocks_facebook_page', 'http://www.facebook.com/pages/Amber+Road/507641042664548'),
  );
  $form['social']['amberroad_blocks_googlep_page'] = array(
    '#title' => t('Google Plus'),
    '#type' => 'textfield',
    '#default_value' => variable_get('amberroad_blocks_googlep_page', 'https://plus.google.com/100833232171840180230?prsrc=3'),
  );
  $form['social']['amberroad_blocks_pinterest_page'] = array(
    '#title' => t('Pinterest'),
    '#type' => 'textfield',
    '#default_value' => variable_get('amberroad_blocks_pinterest_page', 'http://www.pinterest.com/gtmbestpractice'),
  );
  $form['career']['amberroad_blocks_career_mail_ind'] = array(
    '#title' => t('Mail Id for India'),
    '#type' => 'textfield',
    '#default_value' => variable_get('amberroad_blocks_career_mail_ind', 'careersIND@amberroad.com'),
  );
  $form['career']['amberroad_blocks_career_mail_us'] = array(
    '#title' => t('Mail Id for United States'),
    '#type' => 'textfield',
    '#default_value' => variable_get('amberroad_blocks_career_mail_us', 'careersUSA@amberroad.com'),
  );
  $form['career']['amberroad_blocks_career_mail_eu'] = array(
    '#title' => t('Mail Id for Europe'),
    '#type' => 'textfield',
    '#default_value' => variable_get('amberroad_blocks_career_mail_eu', 'careersEU@amberroad.com'),
  );
  $form['career']['amberroad_blocks_career_mail_ap'] = array(
    '#title' => t('Mail if for Asia Pacific'),
    '#type' => 'textfield',
    '#default_value' => variable_get('amberroad_blocks_career_mail_ap', 'careersAP@amberroad.com'),
  );
  $form['promo_text']['amberroad_homepage_promo_text'] = array(
    '#title' => t('Copyright Text'),
    '#type' => 'textarea',
    '#default_value' => variable_get('amberroad_homepage_promo_text', t('Our Global Trade Management Software Enables Goods to Flow Unimpeded Across <br>
      International Borders in the Most Efficient, Compliant and Profitable Way')),
 
  );
  $form['amberroad_blocks_copyright'] = array(
    '#title' => t('Copyright Text'),
    '#type' => 'textfield',
    '#default_value' => variable_get('amberroad_blocks_copyright', '© ' . date('Y') . ' Amber Road, Inc.'),
  );

  return system_settings_form($form);
}