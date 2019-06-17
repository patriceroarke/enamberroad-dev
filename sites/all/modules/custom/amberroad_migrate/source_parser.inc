<?php

interface SourceParser {
  
  /**
   * Init.
   *
   * @param $id
   *  The filename, e.g. pm7205.html
   * @param $html
   *  The full HTML data as loaded from the file.
   */
  public function init($id, $html);

  /**
   * Replace characters.
   */
  public function charTransform();
  
  /**
   * Deal with encodings.
   */
  public function fixEncoding();

  /**
   * Wrap an HTML fragment in the correct head/meta tags so that UTF-8 is
   * correctly detected, and for the parsers and tidiers.
   */
  public function wrapHTML();
  
  /**
   * Create the QueryPath object.
   */
  public function initQP();

  /**
   * Remove the comments from the HTML.
   */
  public function stripComments();
}