import React from 'react';
import Helmet from 'react-helmet';
import { graphql } from 'gatsby';
import styled, { css, createGlobalStyle } from 'styled-components';
import _ from 'lodash';
import {
  breakpoints,
  colors,
  fonts,
  GlobalStyles,
  ThemeProvider,
} from '../theme';
import {
  MenuButton,
  NavBar,
  ContentContainer,
  AppContainer,
  PageTitle,
} from '../components/Layout';
import { SyntaxProvider, SyntaxToggle } from '../components/Syntax';

import { Try } from '../components/try/playground/try';
import '../components/try/assets/css/codemirror.css';

let TryStyles = createGlobalStyle`
/* try playground style */
.try-inner {
  position: fixed;
  display: flex;
  flex-direction: column;
  padding-top: 50px;
  top: 0;
  bottom: 0;
  left: 0;
  right: 0;
}
/* small screens size. The nav bar becomes two lines */
@media (max-width: 735px) {
  .try-inner {
    padding-top: 100px;
  }
}
.try-buttons {
  position: relative;
  display: flex;
  flex-direction: row;
  justify-content: flex-end;
  background: white;
  text-align: center;
  align-items: stretch;
}
.try-button {
  font-size: 14px;
  display: flex;
  flex-direction: row;
  padding: 1em 2em;
  align-items: center;
}
.try-button:hover {
  color: $primaryColor;
  cursor: pointer;
}
.try-button-right-border {
  border-right: 1px solid #d6d4d4;
}

.arrow {
  position: absolute;
  content: '';
  bottom: 100%;
  height: 0;
  width: 0;
  border: .5em solid transparent;
  pointer-events: none;
  border-bottom-color: rgba(0, 0, 0, .6);
  margin-left: .5em;
}
.try-tooltip {
  position: absolute;
  z-index: 100;
  top: 100%;
  background: rgba(0, 0, 0, .6);
  color: white;
  padding: .15em .8em;
  border-radius: .25em;
  font-size: .8rem;
}

.try-button-share {
  position: relative;
}
.try-button-share input {
  background: #f6f4f4;
  transition: all 250ms;
  width: 0;
  padding: 0;
  border: none;
  outline: none;
}
.try-button-share:hover input {
  width: 25vw;
  margin-right: 1em;
}
.try-button-share:hover .try-tooltip {
  display: block;
}
.try-button-share .try-tooltip {
  display: none;
  right: 1em;
  white-space: nowrap;
}
.try-button-share .try-tooltip .arrow {
  right: 2.5em;
}

.try-button-note:hover .try-tooltip {
  display: block;
  width: 50%;
  text-align: left;
}
.try-button-note .try-tooltip {
  display: none;
}

.try-button-examples:hover .try-button-examples-list {
  display: grid;
  grid-template-columns: 1fr 1fr;
}
.try-button-examples-list {
  position: absolute;
  color: #555;
  z-index: 100;
  background: white;
  display: none;
  top: 100%;
  left: 0;
  min-width: 50vw;
  box-shadow: 1px 1px 1px rgba(0, 0, 0, .2);
  border-top: 1px solid #d6d4d4;
  padding: 1em 0 1em 0;
}
.try-button-examples-list li {
  margin: 0;
  padding: .5em 2em;
  list-style: none;
}
.try-button-examples-list li:hover {
  color: $primaryColor;
}

.try-button-reasonreact-checkbox {
  display: flex;
  margin-left: 1em;
  align-self: center;
  justify-self: center;
}

.try-grid {
  height: 100%;
  display: grid;
  grid-template-columns: 1fr 1fr;
  grid-template-rows: 1fr 1fr;
  /* needed so that firefox height works: https://github.com/reasonml/reasonml.github.io/issues/299 */
  min-height: 0;
}
/* small screens size. The nav bar becomes two lines */
@media (max-width: 735px) {
  .try-grid {
    grid-template-columns: 1fr;
  }
}
.try-grid-editor {
  background: #f6f4f4;
  border: 1px solid #d6d4d4;
  border-bottom: none;
  border-right: none;
  position: relative;
  overflow: auto;
  display: flex;
  flex-direction: column;
  flex: 1;
}
.try-label {
  display: flex;
  position: absolute;
  top: 0;
  right: 0;
  background-color: rgba(246, 244, 244, 0.8);
  padding: 1em;
  text-transform: uppercase;
  color: #988;
  font-size: 12;
  line-height: 12px;
  flex-direction: row;
  align-items: center;
  z-index: 20;
  border-radius: 0 0 0 5px;
  transition: opacity 0.25s;
  backdrop-filter: blur(5px);
  -webkit-backdrop-filter: blur(5px);
  pointer-events:none;
}
.try-grid-editor:hover .try-label {
  opacity: 0;
}
.try-output {
  display: flex;
  flex-direction: row;
  overflow: scroll;
}
.try-grid .CodeMirror {
  flex: 1;
}
.try-codemirror-wrap {
  display: flex;
  flex: 1;
  flex-direction: column;
  min-height: 0;
}

.try-error-warning {
  font-family: "Lucida Console", Monaco, monospace;
  font-size: 11px;
  color: rgb(196, 199, 196);
  padding: 0px 15px;
  background-color: rgb(39, 41, 44);
  overflow: scroll;
  flex: 1;
  line-height: 15px;
}

.try-output-line {
  font-family: "Lucida Console", Monaco, monospace;
  white-space: pre;
}
`

export default () => {
  return (
    <ThemeProvider>
      <SyntaxProvider>
        <Helmet>
          <link
            href="https://fonts.googleapis.com/css?family=Roboto+Mono&display=swap"
            rel="stylesheet"
          />
          <script type="text/javascript" src="/js/bsReasonStandard.js" />
          <script type="text/javascript" src="/js/stdlibBundle.js" />
          <script type="text/javascript" src="/js/reasonStandardBundle.js" />
        </Helmet>
        <GlobalStyles />
        <AppContainer>
          <ContentContainer>
            <NavBar />
            <main
              css={css`
                align-self: center;
                display: flex;
                flex: 1;
                flex-direction: column;
                max-width: 970px;
                width: 100%;
              `}
            >
              <div
                css={css`
                  max-width: 750px;
                `}
              />
              <TryStyles />

              <Try />
            </main>
          </ContentContainer>
        </AppContainer>
      </SyntaxProvider>
    </ThemeProvider>
  );
};
