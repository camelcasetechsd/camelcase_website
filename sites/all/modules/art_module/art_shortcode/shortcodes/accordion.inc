<?php

/**
 * Definition of Accordion Shortcode
 */

/**
 * Implements hook_shortcode_info
 */

global $accordion_item;
function _accordion_shortcode_info(&$shortcodes) {
	$shortcodes['accordion'] = array(
		'title' => t('Accordion'),
		'description' => t('Create an Accordion'),
		'process callback' => 'art_shortcode_accordion',
		'tips callback' => 'art_shortcode_accordion_tip',
	);
	
	$shortcodes['accordion_item'] = array(
		'title' => t('Accordion Item'),
		'description' => t('Create an Accordion Item'),
		'process callback' => 'art_shortcode_accordion_item',
		'tips callback' => 'art_shortcode_accordion_item_tip',
	);
	
	return $shortcodes;
}

/**
 * Accordion Content
 */
function art_shortcode_accordion($attrs, $text) {
	$attrs = shortcode_attrs(array(
			'id' => 'sup-accordion',
			'class' => '',
		),
		$attrs
	);
	
	$class = shortcode_add_class($attrs['class'],'clearfix');
	return theme('accordion',array('id' => $attrs['id'],'class' => $class,'content' => $text));
}

/**
 * Accordion Item Content
 */
function art_shortcode_accordion_item($attrs,$text) {
	$attrs = shortcode_attrs(array(
			'title' => '',
			'class' => '',
			'icon' => '',
		),
		$attrs
	);
	
	$class = shortcode_add_class($attrs['class'],'accordion-toggle');
	return theme('accordion_item',array('title' => $attrs['title'],'class' => $class,'content' => $text,'icon'=>$attrs['icon']));
}

/**
 * Accordion theme
 */
function _accordion_theme(&$themes) {
	$themes['accordion'] = array(
		'variables' => array(
			'id' => '',
			'class' => '',
			'content' => ''
		)
	);
	
	$themes['accordion_item'] = array(
		'variables' => array(
			'title' => '',
			'class' => '',
			'content' => '',
			'icon' =>'',
		)
	);
	
	return $themes;
}

/**
 * Theme accordion
 */
function theme_accordion($vars) {
	global $accordion_item;
	$accordion_item = 0;
	$id = drupal_html_id('spaccordion');//$vars['id'];
	$class = $vars['class'];
	$content = $vars['content'];
	return '<dl id="'.$id.'" class="accordion">'.str_replace('@accordion_id',$id,$content).'</dl>';
}

/**
 * Theme Accordion Item
 */
function theme_accordion_item($vars) {
	global $accordion_item;
	$id = drupal_html_id('spcollapse');
	$title = $vars['title'];
	$class = $vars['class'];
	$content = $vars['content'];
	$icon = $vars['icon'];
	$icon_html = "";
	if($icon){
		$icon_html = "<em class=\"fa fa-{$icon}\"></em> ";
	}
	$output = '';
	if($accordion_item == 0){
		$output .= '<dt class="active"><i class="fa fa-plus"></i>'.$title.$icon_html.'</dt>';
		$accordion_item ++;
	}else{
		$output .= '<dt><i class="fa fa-plus"></i>'.$title.$icon_html.'</dt>';
	}
	$output .= '<dd><p>'.$content.'</p></dd>';
	
	return $output;
}