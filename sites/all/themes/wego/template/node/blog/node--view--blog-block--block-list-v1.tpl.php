<?php
global $base_url;
global $default_img;

$image = $default_img;
if (isset($node->field_image['und'])) {
    $image = file_create_url($node->field_image['und'][0]['uri']);
}
?>
<li>
    <div class="pic">
        <img src="<?php echo $image; ?>" width="1170" height="430" alt="">
        <div class="wrap"><div class="date"><div><?php print format_date($node->created, 'custom', 'd'); ?><span>&nbsp;<?php print format_date($node->created, 'custom', 'M'); ?></span></div></div></div>
        <a href="<?php print $node_url; ?>" class="link"></a>
        <a href="<?php echo $image; ?>" class="fancybox zoom"><i class="fa fa-search-plus"></i></a>
    </div>
    <div class="summary">
        <h3><?php print $title; ?></h3>
        <div class="info">
            <div><i class="fa fa-comment"></i><span><?php print $comment_count; ?> <?php print t('Comments'); ?></span></div>
            <div><i class="fa fa-user"></i><?php print str_replace('xml:lang=""', '', $name); ?></div>
        </div>
        <?php print $node->body['und'][0]['summary']; ?>
        <a href="<?php print $node_url; ?>" class="more"><span><?php print t('Read More'); ?> <i class="fa fa-arrow-circle-o-right"></i></span></a>
    </div>
</li>
