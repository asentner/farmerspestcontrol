<div <?php print $attributes; ?>>
  <div class="content accordion" <?php print $content_attributes; ?>>
    <?php print render($content['field_question']); ?>
    <?php print render($content['field_answer']); ?>
  </div>
</div>
